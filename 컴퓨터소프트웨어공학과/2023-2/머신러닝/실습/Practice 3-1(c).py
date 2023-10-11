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

from sklearn import svm

#1.svm분류 모델인 SVC객체를 생성하여 변수 s에 대입한다.
s=svm.SVC(gamma=0.1, C=10) #gamma는 하이퍼 매개변수
#2.iris 데이터로 svm 학습한다
s.fit(d.data, d.target) #d.data, d.target은 훈련 집합

#3.d.data의 101번째와 51번째 샘플을 변형시켜 새로운 데이터 new_d를 생성한다.
new_d=[[6.4, 3.2, 6.0, 2.5],[7.1, 3.1, 4.7, 1.35]]

#4.새로운 데이터를 훈련집합으로 넣어 새로운 데이터의 부류를 예측한다.
res=s.predict(new_d)
print("새로운 2개 샘플의 부류는", res)
#새로운 데이터 샘플의 부류는 각각 101번째와 51번째 샘플을 변형시켰으므로 2와 1이 나온다.
#1~50은 레이블0 / 51~100은 레이블1 / 101~150은 레이블2 이기 때문이다. 