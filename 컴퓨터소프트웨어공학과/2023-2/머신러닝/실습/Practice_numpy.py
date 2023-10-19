import numpy as np
a=np.array([12,8,20,17,15])
print(a)
a.sort()
print(dir(a))
type(a)
print(a.shape)

b=np.array([[12,3,4.0],[1,4,5]])
print(b.dtype)
print(a.dtype)

print(b.ndim)
print(b.shape)
c=np.array([[[1,3,0,1],[1,1,4,2],[3,3,4,1]],[[2,1,2,1],[1,0,1,0],[1,5,6,2]]])
print(c)
print(c.shape)

d=np.zeros([2,3])
print(d.dtype)
e=np.random.random([2,5])
print(e)
f=np.arange(1,20,2.5) #1이상 20미만, 2.5씩 증가하여 배열에 요소로 추가
print(f)

x=10
y=x
y=12
print(x,y)

a=np.array([10,20,30,40])
b=a[0]=-10 #같은 메모리를 공유하여 a와 b 배열의 값 모두 바꿈
print(a,b)
c=a.copy()
c[1]=-20 #카피함, 다른 메모리를 공유하여 바꾼 배열만 바뀜
print(a,c)


a=np.array([1,2,3,4,5,6])
b=a.reshape(2,3) #2행 3열로 변경
print(a)
print(b)

a[4]=-5 #a를 바꾸면 b도 바뀜 why? => b는 a배열의 reshape이기 때문이다.s
print(b)

a=np.array([[1,2,3],[4,5,6]])
b=a.T #3행 2열로 바뀜 => 왜? 서칭하기
print(b)

a=np.array([ [3,2,-2,0,1], [2,-3,4,5,2], [0,1,-2,-3,2] ])
print(a)
print("\n sum 실습 \n", a.sum())
print("\n axis=0 실습 \n", a.sum(axis=0))
print("\n axis=1 실습 \n", a.sum(axis=1))
print("\n 누적값 실습 \n", a.cumsum(axis=0))
print("\n max 실습1 \n", a.max(axis=0))
print("\n max 실습2 \n", a.max(axis=1))
print("\n 최대값이 있는 인덱스 찾기 \n", a.argmax(axis=0))

positive=a>0
print("\n 0보다 크면 True 작으면 False \n", positive)

b=a[positive]
print("\n 0보다 큰 값만 필터링\n", b)

print("\n 0보다 큰 값만 필터링하여 합하기 \n", b.sum())

a=np.array([1,2,3])
b=np.array([4,5,6])
c=np.array([[7,8,9],[1,4,7]])

print("\n a와 b를 수직으로 합치기 \n", np.vstack([a,b]))
print("\n a와 c를 수직으로 합치기 \n", np.vstack([a,c]))
print("\n a와 b를 수평으로 합치기 \n", np.hstack([a,b]))
      
      #아래 코드는 수평으로 합칠 수 없으므로 에러 발생

#print("\n a와 c를 수직으로 합치기 \n", np.hstack([a,c])

a=np.array([1,2,3,4,5])
b=np.array([0,1,2,6,1])
c=np.array([np.pi/2, np.pi, np.pi*2])
print("\n 파이값 출력하기 \n", c)
print("\n a와 b를 합치기 \n", np.add(a,b))
print("\n a에 로그값 씌우기 \n", np.log10(a))
print("\n a가 b보다 큰지 비교후 T/F로 반환 \n", np.greater(a,b)) #a가 b보다 큰지 비교후 T/F로 반환
print("\n a와 b 비교 후 큰 값 반환 \n", np.maximum(a,b)) #a와 b 비교 후 큰 값 반환
print("\n 소수점 자르기 \n", c.round(2)) #소수점 2자리로 제한

a=np.array([ [1,2,3,4] , [0,1,2,3], [-1,0,1,2] ])
b=np.array([[1,1,2,2]]) #a와 b를 합할 시에 b에는 2행 3행이 없으므로 자동으로브로드캐스팅하여 1,1,2,2인 1행을 2행과 3행으로 복사하여 매트릭스를 확장한 후 합한다
print("\n 브로드 캐스팅 실습 \n", a+b) 