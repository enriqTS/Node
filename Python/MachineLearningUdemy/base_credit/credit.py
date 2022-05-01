import pandas as pd
import numpy as np
import plotly.express as px
from sklearn.preprocessing import StandardScaler

base_credit = pd.read_csv('Python\MachineLearningUdemy\/base_credit\credit_data.csv')

base_credit.describe()

np.unique(base_credit['default'], return_counts=True)

#ax = sns.countplot(x = base_credit['loan_status'])
#plt.show()

#ax = plt.hist(x = base_credit['person_age'])
#plt.show()

#ax = sns.countplot(x = base_credit['person_income'])
#plt.show() #Tem que import matplotlib.plotly

base_credit = base_credit.drop(base_credit[base_credit['age'] < 0].index)

grafico = px.scatter_matrix(base_credit, dimensions=['age', 'income','loan'], color ='default')
grafico.show()

print(base_credit.mean())

print(base_credit.isnull().sum())

base_credit['age'].fillna(base_credit['age'].mean(), inplace = True)

print(base_credit.isnull().sum())

grafico = px.scatter_matrix(base_credit, dimensions=['age', 'income','loan'], color ='default')
grafico.show()

x_credit = base_credit.iloc[:,1:4].values

y_credit = base_credit.iloc[:, 4].values

scaler_credit = StandardScaler()
x_credit = scaler_credit.fit_transform(x_credit)