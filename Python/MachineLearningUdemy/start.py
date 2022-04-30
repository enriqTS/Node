import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib as plt
import plotly.express as px

base_credit = pd.read_csv('Python\MachineLearningUdemy\credit_risk_dataset.csv')

base_credit.describe()

#np.unique(base_credit['loan_status'], return_counts=True)

#ax = sns.countplot(x = base_credit['loan_status'])
#plt.show()

#ax = plt.hist(x = base_credit['person_age'])
#plt.show()

#ax = sns.countplot(x = base_credit['person_income'])
#plt.show() #Tem que import matplotlib.plotly

base_credit2 = base_credit.drop(base_credit[base_credit['person_age'] > 119].index)

grafico = px.scatter_matrix(base_credit2, dimensions=['person_age', 'person_income','loan_amnt'], color ='loan_status')
grafico.show()

print(base_credit.mean())
print(base_credit2.mean())