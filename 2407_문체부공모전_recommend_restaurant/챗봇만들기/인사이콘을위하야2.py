#!/usr/bin/env python
# coding: utf-8

# <h1>Table of Contents<span class="tocSkip"></span></h1>
# <div class="toc"><ul class="toc-item"></ul></div>

# In[2]:


openai_api_key = ''  # OpenAI API 키를 입력하세요


# In[ ]:


from langchain_openai import ChatOpenAI
from langchain.prompts import PromptTemplate
from langchain.chains import LLMChain
import streamlit as st
import time

openai_api_key = st.secrets["default"]["api_key"]


# OpenAI API 설정
llm = ChatOpenAI(api_key=openai_api_key, model_name="gpt-4o")

# 프롬프트 템플릿 설정
prompt_template = PromptTemplate(
    input_variables=["query"],
    template="""
    You are an AI assistant that helps users find restaurants. Extract the following information from the user's query:
    
    1. TPO (one of the following: 회식, 카공, 혼밥, 데이트, 밥약). If not specified, default to "TPO무관(맛집추천)".
    2. Location (subway station name). If not specified, default to "지역무관(전체지역추천)".
    3. Taste preferences. If not specified, default to "맛무관(no편식)". If the user mentions disliking a specific taste, add "X" to the end (e.g., "매운맛X").
    4. Cuisine category (e.g., 한식, 중식, 양식). If not specified, default to "카테고리무관".
    5. Additional conditions (if specified):
       - Parking availability (주차 가능)
       - Reservation availability (예약 가능)
       - Group seating availability (단체석 가능)

    User's query: {query}
    Extracted information:
    """
)


# LLM 체인 설정
llm_chain = LLMChain(
    llm=llm,
    prompt=prompt_template
)

def extract_restaurant_info(user_query):
    response = llm_chain.run(query=user_query)
    return response

st.title("우리팀화이팅~~~")



user_query = ""
extracted_info = ""
is_confirmed = False
iteration = 0

while not is_confirmed:
    iteration += 1
    user_query = st.text_input("원하는 음식점의 조건을 입력하세요", key=f"user_query_{iteration}")
    
    while not user_query:
        time.sleep(0.5)
        
    extracted_info = extract_restaurant_info(user_query)
    st.write(extracted_info)

    col1, col2 = st.columns(2)
    
    st.write('위 내용이 맞으면 예, 틀리면 아니요를 눌러주세요.')
    with col1:
        yes_button = st.button("예", key=f"yes_button_{iteration}")
    with col2:
        no_button = st.button("아니요", key=f"no_button_{iteration}")
    
    while not (yes_button or no_button):
        time.sleep(0.5)
    
    if yes_button:
        is_confirmed = True
    elif no_button:
        user_query = ""
        st.write("조건을 다시 입력하세요.")
        continue

st.write("전달해주신 내용을 기반으로 추천을 진행합니다...")


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




