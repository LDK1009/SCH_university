from sklearn import datasets #sklearn 모듈의 datasets 클래스를 불러온다

d=datasets.load_iris() #load_iris함수를 호출하여 iris 데이터셋을 읽어 객체 d에 저장한다
print(d.DESCR)  #객체d의 DESCR변수를 출력한다.
#여기서 DESCR은 description이다.
#즉, 객체의 샘플 수, 특징, 그에 따른 분류 종류 등을 설명해놓은 텍스트이다. 

for i in range(0, len(d.data)):
    print(i+1, d.data[i], d.target[i]) 
    #샘플 수가 150개이므로 i+1이 150까지 올라간다
    #d.data는 특징 벡터이며 Attribute가 4개 였으므로 4개다.
    #d.target은 레이블이며 분류 종류가 3개 였으므로 0,1,2 로 구분된다