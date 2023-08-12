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
                source=Image.open(f"crawled_img_ori/{rank}_{brand}.jpg"),
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
    
if __name__=='__main__':
    print()
    print('1. 진정제품군 중 상품별 시각화')
    print('2. 진정제품군 상위 11개 브랜드 시각화')
    print('3. 진정제품군 상위 11개 브랜드 변수 상관관계 시각화')
    option = int(input('원하는 시각화 옵션을 숫자로 입력하세요. : '))
    try :
        if option == 1:
            visualization_by_product("올리브영랭크100위화장품정보+유튜브데이터.xlsx")
        elif option == 2:
            visualization_by_brand('올리브영_진정_상위20.xlsx')
        else:
            visualization_by_corr("올리브영_진정_상위20.xlsx")
    except:
        print('파일 에러 발생.필요한 데이터는 아래와 같습니다.')
        print('올리브영랭크100위화장품정보+유튜브데이터.xlsx')
        print('올리브영_진정_상위20.xlsx')
