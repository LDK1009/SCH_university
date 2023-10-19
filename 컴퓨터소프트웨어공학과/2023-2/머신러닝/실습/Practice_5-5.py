# TensorFlow 라이브러리 불러오기
import tensorflow as tf

# 입력 데이터 및 정답 레이블 정의
x = [ [0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0] ]
y = [ [-1], [1], [1], [1] ]

# 가중치와 편향을 변수로 선언하고 초기화
# 가중치는 -0.5에서 0.5 사이의 균일 분포로 초기화
w = tf.Variable(tf.random.uniform([2,1], -0.5, 0.5))
# 편향은 0으로 초기화
b = tf.Variable(tf.zeros([1]))

# 확률적 경사 하강법 옵티마이저 설정
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

# 순전파 함수: 입력에서 출력으로의 변환 계산
def forward():
    s = tf.add(tf.matmul(x, w), b)  # 선형 변환
    o = tf.tanh(s)                  # 활성화 함수로 tanh 사용
    return o

# 손실 함수: 예측과 실제 값 간의 차이 계산
def loss():
    o = forward()
    return tf.reduce_mean((y - o) ** 2)  # 평균 제곱 오차

# 500번 반복하여 학습
for i in range(500):
    # 손실 함수를 최소화하도록 w, b 업데이트
    opt.minimize(loss, var_list=[w,b])
    if(i % 100 == 0):  # 100번마다 손실 출력
        print('loss at epoch', i, '=', loss().numpy())
        
# 최종 출력값 계산
o = forward()
print(o)
