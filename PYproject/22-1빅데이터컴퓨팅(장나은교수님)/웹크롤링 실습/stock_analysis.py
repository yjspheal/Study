import math
from urllib.request import *
from bs4 import *
import matplotlib.pyplot as plt

def inputCompanyAndDays():
    com_codes = ["005930", "009540", "271980"]
    com_names = ["samsung", "ksoe", "jeil_pharm"]
    print("1:samsung, 2:ksoe, 3:jeil_pharm")
    com = int(input("회사를 고르세요 : "))
    Days = int(input("종가 추출 기간을 입력하세요(20의 배수가 되도록 상향 조정합니다) : "))
    return com_codes[com-1], com_names[com-1], Days

def extractLastPrice(webUrl, DN):
    pList = []
    PN = int(math.ceil(DN / 20))
    
    for pn in range(1,PN+1):
        req = Request(f'{webUrl}&page={pn}')
        req.add_header('User-Agent', 'Mozilla/5.0')
        
        wPage = urlopen(req)
        soup = BeautifulSoup(wPage,"html.parser")
        trList = soup.find_all("tr", {"onmouseover" : "mouseOver(this)"})
        
        for tr in trList:
            tdList = tr.find_all("td")
            price = tdList[1].get_text()
            price = int(price.replace("," , ""))
            pList.append(price)

    pList.reverse()
    return pList

def makeMA(pList, numMA):
    mSum = pList[0] * numMA
    Q = [pList[0]] * numMA
    mList = list()

    for p in pList:
        mSum = mSum - Q.pop(0)
        mSum = mSum + p
        mList.append(mSum / numMA)
        Q.append(p)
        
    return mList


def drawGraph(mList):
    plt.plot(list(range(-len(mList) + 1,1,1)),mList)


    
com_code, com_name, days = inputCompanyAndDays()
url = f'https://finance.naver.com/item/frgn.nhn?code={com_code}'

prices = extractLastPrice(url, days)
drawGraph(prices)   #일일 종가 그래프

for n in [5,20,60]:
    prices_means = makeMA(prices, n)
    drawGraph(prices_means) #5, 20, 60 종가 그래프

plt.xlabel("Day")
plt.grid(True)
plt.legend([com_name, '5MA','20MA','60MA'], loc = "upper left")
plt.show()
