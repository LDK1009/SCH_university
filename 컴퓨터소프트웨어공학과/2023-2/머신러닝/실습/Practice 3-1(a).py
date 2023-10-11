from sklearn import datasets #sklearn 모듈의 datasets 클래스를 불러온다

d=datasets.load_iris() #load_iris함수를 호출하여 iris 데이터셋을 읽어 객체 d에 저장한다
print(d.DESCR)  #객체d의 DESCR변수를 출력한다
