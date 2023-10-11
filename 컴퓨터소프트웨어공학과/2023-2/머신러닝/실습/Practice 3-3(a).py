from sklearn import datasets
import matplotlib.pyplot as plt

digit=datasets.load_digits() #손글씨 숫자 데이터셋을 로드합니다.
plt.figure(figsize=(5,5)) #크기가 5x5 인치인 새로운 Matplotlib 피규어 (플롯)를 생성합니다.
plt.imshow(digit.images[0], cmap=plt.cm.gray_r, interpolation='nearest') #0번 샘플을 그림
#데이터셋의 첫 번째 샘플 이미지를 imshow()를 사용하여 표시합니다.
#cmap=plt.cm.gray_r 인수는 이미지를 표시하는 데 사용할 컬러맵이 회색조임을 지정
#interpolation='nearest'는 이미지를 표시하는 데 사용할 보간 방법을 지정합니다.
plt.show() #Matplotlib 플롯을 표시합니다. 이로써 손글씨 숫자 이미지가 표시됩니다.
print(digit.data[0]) #0번 샘플의 화솟값을 출력
print("이 숫자는", digit.target[0],"입니다") #첫 번째 샘플 이미지의 대상 레이블을 출력