#!/usr/bin/env python
# coding: utf-8

#####20171228 박현진 #########################################################################################################
#oliveyoung_crawling.py
import urllib.request
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image
import re
from bs4 import BeautifulSoup
from selenium import webdriver
from tqdm import tqdm
from selenium.webdriver.common.keys import Keys
keys=Keys()
import time
import os
import warnings
warnings.filterwarnings(action='ignore')

###파이프라인 1. 올리브영 랭킹 페이지 제품 100개 리스트 만들기 
def crawling_top100_list():
    #판매랭킹 베이스 url 
    main_url = 'https://www.oliveyoung.co.kr/store/main/getBestList.do'

    #크롬 드라이버 열기 
    driver = webdriver.Chrome(".\chromedriver.exe") 
    driver.get(main_url)

    #로딩 될때까지 기다리기 
    driver.implicitly_wait(5) # seconds

    #'스킨케어' 클릭 
    skincare_button='#Container > div.best-area > div.common-menu > ul > li:nth-child(2) > button'
    key = driver.find_element_by_css_selector(skincare_button)
    key.click()
    time.sleep(3)

    #상품 상세정보를 저장할 데이터프레임 
    df=pd.DataFrame(columns=['순위','상품이름','브랜드','가격','상세페이지'])

    #각 라인마다 4개의 원소를 들고올것, 반복횟수: (ul:nth-child(1)~ul:nth-child(25))
    rank=1
    for line in range(1, 26):

        prod_box='#Container > div.best-area > div.TabsConts.on > ul:nth-child('+str(line)+')'

        for idx in range(1,5):
            if idx %4==1: ##첫번째 박스만 태그가 'flag'로 되어 있으므로 예외처리 
                nth_box= ' > li.flag'

            elif idx %4==0:#네번째박스
                nth_box = '> li:nth-child('+str(4)+')'

            else : ##두,세번째 박스 
                nth_box = '> li:nth-child('+str(idx%4)+')'
            #상세페이지 url
            prod_detail_tag = prod_box + nth_box+ ' > div > a'
            #브랜드
            brand_tag=  prod_box + nth_box+  ' > div > div > a > span'
            #상품이름
            prod_name_tag=  prod_box + nth_box+  ' div > div > a > p'
            #가격
            price_tag =  prod_box + nth_box+  ' > div > p.prd_price > span.tx_cur > span'
            #상품이미지
            img_tag= prod_box + nth_box +' > div > a > img'
            
            #태그로 읽어들인 텍스트에서 속성추출, 전처리 
            prod_detail_url = driver.find_element_by_css_selector(prod_detail_tag).get_attribute('href')
            brand = driver.find_element_by_css_selector(brand_tag).text
            prod_name = driver.find_element_by_css_selector(prod_name_tag).text
            price =  int(driver.find_element_by_css_selector(price_tag).text.replace(',',''))
            df= df.append(pd.DataFrame([[rank, prod_name, brand, price, prod_detail_url]],columns=['순위','상품이름','브랜드','가격','상세페이지']), ignore_index=True)
            
            #크롤링 확인을 위한 코드 
            print(brand+':'+prod_name)
            print(prod_detail_url)

            #크롤링한 이미지 저장
            img = driver.find_element_by_css_selector(img_tag).get_attribute('src')
            #1. 이미지 저장 폴더 설정 (없으면 폴더 생성)
            try:
                os.mkdir("new_crawled_img") 
            except FileExistsError:
                print('new_crawled_img 파일이 이미 존재합니다. 해당 폴더에 이미지를 크롤링합니다.')
            filename = 'new_crawled_img/'+str(rank)+'_'+brand+'.jpg'

            #2. 경로내 중복되는 파일 명 확인
            try:
                # 중복되는 파일 명이 없다면 패스
                if not os.path.isfile(filename):
                    pass
                # 중복된다면 문구 출력 후 다음 이미지로 넘어감
                else:
                    print('이전에 다운로드한 이미지가 존재합니다.')
                    pass
            except OSError:
                print ('os error')
                #sys.exit(0)

            #3. 이미지 저장
            try:
                req = urllib.request.Request(img, headers={'User-Agent': 'Mozilla/5.0'})
                imgUrl = urllib.request.urlopen(req).read() #웹 페이지 상의 이미지를 불러옴
                with open(filename,"wb") as f: #디렉토리 오픈
                    f.write(imgUrl) #파일 저장

            except urllib.error.HTTPError:
                print('이미지 저장 에러')
                pass 

            #반복문에서 순위를 계산중이므로, 하나의 상품에 대한 크롤링이 전부 끝나면 순위 올려주기 
            rank+=1

            time.sleep(1)
    df.to_excel('(new)올리브영랭크100위화장품정보.xlsx')


##파이프라인 2. 100개 리스트 행마다 반복하며 상세페이지 들어가서 상세 정보 크롤링 
def iter_dataframe(df):
    def crawl_olive(main_url):
        driver = webdriver.Chrome(".\chromedriver.exe") 
        time.sleep(3)
        driver.get(main_url)
        driver.implicitly_wait(5) 
        key = driver.find_element_by_css_selector('#reviewInfo > a')

        key.click()
        time.sleep(3)
        
        try: #상세리뷰가 있거나, 리뷰의 개수가 있는 경우에만 긁어야 에러가 나지 않으므로 try안에 넣음
            rating = driver.find_element_by_css_selector('#gdasContentsArea > div > div.product_rating_area > div > div.star_area')
            grpah = driver.find_element_by_css_selector('#gdasContentsArea > div > div.product_rating_area > div > div.graph_area')
            detail = driver.find_element_by_css_selector('#gdasContentsArea > div > div.poll_all.clrfix')

            rating_text= rating.text.split('\n')
            graph_text= grpah.text.split('\n')
            detail_text= detail.text.split('\n')
            review_n = int(re.sub(r'[^0-9]', '', rating_text[0]))
            star = float(rating_text[1][:3])
        except:#상세리뷰가 없거나 리뷰가 없는 상품 -> 결측치로 이후에 처리하기 위해 -1값을 대신 넣음 
            review_n=-1
            star=-1
            graph_text=""
            detail_text = ""
            print('상세리뷰가 없거나 리뷰가 없는 상품입니다.:',main_url)
            pass
        return review_n, star, graph_text, detail_text
    
    # 빈 DataFrame 생성하기
    df2=pd.DataFrame(columns=['순위','리뷰개수','별점','별점그래프','타입그래프'])
    
    #받은 올리브영 상품 리스트 데이터프레임에 대해서 반복하면서 상세 리뷰를 채워주는 코드 
    for i in tqdm(df.index):
        rank=i+1
        review_n, star, graph_text, detail_text= crawl_olive(df['상세페이지'][i])
        df2 = df2.append(pd.DataFrame([[rank,review_n, star, graph_text, detail_text]], columns=['순위','리뷰개수','별점','별점그래프','타입그래프']), ignore_index=True)
    
    #원래의 올리브영 데이터프레임과 새로 크롤링한 상세 리뷰 데이터를 합집합으로 머지해주는 코드 
    merge_df= pd.merge(df, df2, on='순위',how='outer')
    merge_df.drop(['Unnamed: 0'], axis = 1, inplace = True)

    merge_df.to_excel('new_올리브영랭크100위화장품정보_상세페이지.xlsx')
    
def olive_main():
    print('1차 크롤링 : 올리브영랭크 상위 100위화장품을 크롤링합니다.')
    crawling_top100_list()
    df=pd.read_excel('원본_올리브영랭크100위화장품정보.xlsx')
    print('2차 크롤링 : 올리브영랭크100위화장품정보를 읽어 상세페이지를 크롤링합니다.')
    result_df= iter_dataframe(df)
    print('올리브영 크롤링이 완료되었습니다.')


#####20180488 김민서 #########################################################################################################
from urllib.request import *
from bs4 import BeautifulSoup
import ssl
from selenium import webdriver
from selenium import webdriver
from selenium.webdriver import Chrome
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from openpyxl import Workbook
import pandas as pd

ssl._create_default_https_context = ssl._create_unverified_context

olive = pd.read_excel(r".\원본_올리브영랭크100위화장품정보_상세페이지.xlsx")

#브랜드 이름 추출하는 함수
def product_name(file):
    name_list = [] #브랜드 이름을 담을 리스트
    for i in range(len(file)):
        product_name = file['브랜드'][i] #리스트에 브랜드 저장
        name_list.append(product_name) 
        name_list = list(set(name_list))

    return name_list


#브랜드에 대한 정보들을 알아보는 함수(트렌드 함수)
def trend_index(product): #각 브랜드 이름 인자로 받기
    
    #첫페이지 열기
    driver = webdriver.Chrome('.\chromedriver.exe')
    driver.implicitly_wait(10) # seconds
    driver.get("https://www.itemscout.io/keyword")
    driver.implicitly_wait(10) # seconds
    
    #키워드 입력, Enter
    keyword = driver.find_element_by_class_name("input-keyword")
    keyword.send_keys(product) #브랜드 이름 입력해서 엔터

    enter = '//*[@id="app"]/div/main/div/div/div/div[1]/div[1]/div[1]/div[2]/div[1]/div'
    enter_click = driver.find_element_by_xpath(enter).click()

    driver.implicitly_wait(10) # seconds

    #한 달 검색수
    pre_elem = driver.find_elements_by_class_name("count-stat")[1]
    search_n = pre_elem.text
    search_n = search_n.replace(',','')

    #Top40 6개월 매출
    pre_elem = driver.find_elements_by_class_name("count-stat")[2]
    sales = pre_elem.text
    sales = sales.replace(",","")
    
    #Top40 6개월 판매량
    pre_elem = driver.find_elements_by_class_name("count-stat")[3]
    volume = pre_elem.text
    volume = volume.replace(",","")

    #Top40 평균 가격
    pre_elem = driver.find_elements_by_class_name("count-stat")[4]
    price = pre_elem.text
    price = price.replace(",","")
    
    driver.close() #다 추출하고 나면 창 닫기
    
    return search_n, sales, volume, price

def process(trend): #전처리 함수
    
    search_n = []
    try:
        for i in trend['한 달 검색수']:
            i = int(i.replace("회",""))
            search_n.append(i)

        sales = []
        for i in trend['6개월 매출']:
            if i[:-2] == '만원' : #만원단위는 0네개 붙이고 int
                i = i[:-2]
                i=int(i+'0000')
            else:
                i = int(i[:-2])
                i=int(i+'00000000') #억 단위는 0여덟개 붙이고 int
            sales.append(i)

        sales_volume = []
        for i in trend['6개월 판매량']:
            i = int(i.replace("개",""))
            sales_volume.append(i)

        price = []
        for i in trend['평균 가격']:
            i = int(i.replace("원",""))
            price.append(i)
    except:
        pass
    trend['한 달 검색수'] = search_n
    trend['6개월 매출'] = sales
    trend['6개월 판매량'] = sales_volume
    trend['평균 가격'] = price
    
    

def item_crawl_main():
    n_list = product_name(olive) #olive파일의 브랜드 이름이 담긴 리스트
    wb = Workbook()
    ws1 = wb.active
    ws1.title = "Trend Index"
    ws1.append(["브랜드", "한 달 검색수", "6개월 매출", "6개월 판매량", "평균 가격"])

    for i in n_list: #겹치지 않는 브랜드 명을 담은 리스트를 인자로 받음
        search_n, sales, volume, price = trend_index(i) #함수 호출
        ws1.append([i, search_n, sales, volume, price]) #정보 저장

    wb.save(filename='new_트렌드지수 크롤링(브랜드).xlsx') #끝나고 나면 엑셀로 만들기
    trend = pd.read_excel(r".\원본_트렌드지수 크롤링(브랜드).xlsx")
    process(trend) #전처리하여 사용할 수 있게 데이터 준비
#####20191245 노유정 #########################################################################################################



def youtube_main():
    try :
        youtube_crawling()
        excel_add_youtube()
        make_top20
    except:
        print('파일 에러 발생.필요한 데이터는 아래와 같습니다.')
        print('올리브영랭크100위화장품정보_상세페이지.xlsx')
        print('트렌드 지수(아이템 스카우트)/트렌드지수 크롤링(브랜드).xlsx')
    

#####20171228 박현진 #########################################################################################################
try:
    import plotly.express as px
    from PIL import Image
    import pandas as pd
    import matplotlib.pyplot as plt
    import seaborn as sns
    import numpy as np
    import matplotlib.font_manager as fm
    import warnings
    import plotly.graph_objects as go
except:
    print('!pip install plotly 를 입력하여 패키지를 설치하세요')
    print('!pip install PIL 를 입력하여 패키지를 설치하세요')
    print('!pip install warnings 를 입력하여 패키지를 설치하세요')
    
warnings.filterwarnings(action='ignore')

def visualization_by_corr(excel_file_name):
    #상관계수 표 출력
    df= pd.read_excel(excel_file_name)
    return(df.corr())

def visualization_by_brand(excel_file_name):
    df= pd.read_excel(excel_file_name)
    #그래프 1 : 유투브 컨텐츠 수와 올리브영 리뷰 개수, 해당 회사 매출액을 비교 
    fig = px.scatter(df, x="평균리뷰개수", y="평균좋아요/조회수",
	         size="매출액", color=df.index,
            hover_name="브랜드", log_x=True, size_max=60)
    fig.show()
                  
def visualization_by_product(excel_file_name):
    df = pd.read_excel(excel_file_name)
    df=df[df['진정']>30] #진정제품 상위 30개 필터링

    df['퀄리티'] = df['리뷰개수']+ df['총 댓글수']
    fig = px.scatter(
        df,
        x="퀄리티",
        y="가격",
        hover_name="상품이름",
        hover_data=['브랜드',"가격","총 댓글수", "리뷰개수",'진정']
    )
    fig.update_traces(marker_color="rgba(0,0,0,0)")

    maxDim = df[["총 댓글수",'가격']].max().idxmax()
    maxi = df[maxDim].max()
    for i, row in df.iterrows():
        rank = row['순위']
        brand = row['브랜드']
        fig.add_layout_image(
            dict(
                source=Image.open(f"원본_crawled_img/{rank}_{brand}.jpg"),
                xref="x",
                yref="y",
                xanchor="center",
                yanchor="middle",
                x=row["퀄리티"],
                y=row["가격"],
                #sizex=np.sqrt(row["진정"] / df["진정"].max()) * maxi * 0.2 + maxi * 0.05,
                #sizey=np.sqrt(row["진정"] / df["진정"].max()) * maxi * 0.2 + maxi * 0.05,
                sizex=np.sqrt(row["총 댓글수"] / df["총 댓글수"].max()) * maxi * 0.2 + maxi * 0.05,
                sizey=np.sqrt(row["총 댓글수"] / df["총 댓글수"].max()) * maxi * 0.2 + maxi * 0.05,
                sizing="contain",
                opacity=0.8,
                layer="above"
            )
        )
    fig.update_layout(height=600, width=1000, yaxis_range=[-5e3, 55e3], plot_bgcolor="#dfdfdf")
    fig.show()

def visualization():
    print()
    print('1. 진정제품군 중 상품별 시각화')
    print('2. 진정제품군 상위 11개 브랜드 시각화')
    print('3. 진정제품군 상위 11개 브랜드 변수 상관관계 시각화')
    option = int(input('원하는 시각화 옵션을 숫자로 입력하세요. : '))
    try :
        if option == 1:
            visualization_by_product("원본_올리브영랭크100위화장품정보+유튜브데이터.xlsx")
        elif option == 2:
            visualization_by_brand('원본_올리브영_진정_상위20.xlsx')
        else:
            visualization_by_corr("원본_올리브영_진정_상위20.xlsx")
    except:
        print('파일 에러 발생.필요한 데이터는 아래와 같습니다.')
        print('원본_올리브영랭크100위화장품정보+유튜브데이터.xlsx')
        print('원본_올리브영_진정_상위20.xlsx')
    
if __name__=='__main__':
    from selenium.common.exceptions import TimeoutException, WebDriverException
    #1.올리브영데이터 긁기
    #try: 
        #olive_main()
        #pass
    #except WebDriverException:
        #print('WebDriverException: 로딩이 느려 다시 크롤링을 시작합니다.')
        #df=pd.read_excel('원본_올리브영랭크100위화장품정보.xlsx')
        #print('2차 크롤링 : 올리브영랭크100위화장품정보를 읽어 상세페이지를 크롤링합니다.')
        #result_df= iter_dataframe(df)
        #print('올리브영 크롤링이 완료되었습니다.')

    #2.아이템스카우트 긁기
    #item_crawl_main()
    #3.유투브 긁기
    #youtube_main()
    #상품별, 브랜드별 시각화 
    visualization()
