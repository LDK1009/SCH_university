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


lfw=datasets.fetch_lfw_people(min_faces_per_person=70, resize=0.4) #함수를 사용하여 "LFW (Labeled Faces in the Wild)" 얼굴 데이터셋을 로드합니다. 이 데이터셋은 유명인사들의 얼굴 사진과 해당 얼굴에 대한 레이블을 포함하고 있습니다. 
#min_faces_per_person 매개변수는 각 인물당 최소 얼굴 이미지 수를 지정하며, resize 매개변수는 이미지 크기를 조절합니다.

plt.figure(figsize=(100,5)) #새로운 Matplotlib 피규어 (플롯)를 생성합니다. 이 피규어의 크기는 가로로 20인치, 세로로 5인치입니다.

for i in range(8): #반복문을 사용하여 처음 8개 얼굴 이미지를 시각화합니다.
    plt.subplot(1, 8, i+1) #현재 플롯의 위치를 설정합니다. 1, 8은 플롯을 1행 8열로 배치하겠다는 의미이고, i+1은 현재 플롯의 인덱스를 나타냅니다.
    plt.imshow(lfw.images[i], cmap=plt.cm.bone) #lfw 데이터셋에서 i번째 얼굴 이미지를 표시합니다. cmap=plt.cm.bone은 이미지를 표시하는 데 사용할 컬러맵을 설정합니다. bone 컬러맵은 회색조 스타일의 컬러맵입니다.
     #플롯의 제목을 설정합니다. 얼굴 이미지에 해당하는 레이블을 lfw.target_names에서 가져와 제목으로 설정합니다.

plt.show() #Matplotlib 플롯을 표시합니다. 이로써 처음 8개 얼굴 이미지가 시각화되고, 각 이미지의 레이블이 표시됩니다.

news = datasets.fetch_20newsgroups(subset='train')
print("*****\n", news.data[0], "\n*****")
print("이 문서의 부류는 <", news.target_names[news.target[0]], "> 입니다.")
