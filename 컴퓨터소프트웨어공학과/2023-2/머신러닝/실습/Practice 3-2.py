import plotly.express as px

df = px.data.iris()
#petal_length를 제외함으로써 3차원 공간 구성
fig=px.scatter_3d(df, x='sepal_length', y='sepal_width', z='petal_width', color='species')
fig.show(renderer="browser")