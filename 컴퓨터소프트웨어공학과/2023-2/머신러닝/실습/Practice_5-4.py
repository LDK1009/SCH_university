# TensorFlow 라이브러리 불러오기
import tensorflow as tf

# 입력 데이터 및 정답 레이블 정의
x = [ [0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0] ]
y = [ [-1], [1], [1], [1] ]

# 가중치와 편향을 변수로 선언
w = tf.Variable([ [1.0], [1.0] ])  # 가중치 초기값
b = tf.Variable(-0.5)               # 편향 초기값

# 선형 변환 수행: (x * w + b)
s = tf.add(tf.matmul(x, w), b)

# 결과 값을 -1 또는 1로 변환하기 위한 부호 함수 적용
o = tf.sign(s)

# 결과 출력
print(o)
