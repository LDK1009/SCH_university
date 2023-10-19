# 필요한 Keras 모듈 불러오기
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import SGD

# 입력 데이터와 레이블 정의
x = [ [0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0] ]
y = [ [-1], [1], [1], [1] ]

# 입력과 출력의 차원 정의
n_input = 2
n_output = 1

# Keras의 Sequential 모델을 사용하여 단일 퍼셉트론 모델 구성
perceptron = Sequential()
perceptron.add(Dense(units=n_output, activation='tanh',         # 활성화 함수로 'tanh' 사용
               input_shape=(n_input,),                           # 입력 차원 설정
               kernel_initializer='random_uniform',              # 가중치 초기화 방식 설정
               bias_initializer='zeros'))                        # 편향 초기화 방식 설정

# 모델 컴파일: 손실 함수로 'mse'(평균 제곱 오차) 선택, 최적화 방법으로 SGD 선택
perceptron.compile(loss='mse', optimizer=SGD(learning_rate=0.1), metrics=['mse'])

# 모델 학습: 주어진 데이터를 사용하여 500 epoch 동안 학습
perceptron.fit(x, y, epochs=500, verbose=2)

# 학습된 모델로 예측값 출력
res = perceptron.predict(x)
print(res)
