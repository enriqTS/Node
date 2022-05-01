import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib as plt
import matplotlib.pyplot as plt
import plotly.express as px
from sklearn.preprocessing import StandardScaler, LabelEncoder

base_census = pd.read_csv('Python\MachineLearningUdemy\/base_censo\census.csv')

print(base_census.describe())

print(base_census.isnull().sum())

print(np.unique(base_census['income'], return_counts = True))

# ax = sns.countplot(x = base_census['income'])
# plt.show()

# plt.hist( x = base_census['age'])
# plt.show()

# plt.hist(x = base_census['education-num'])
# plt.show()

# plt.hist(x = base_census['hour-per-week'])
# plt.show()

# grafico = px.treemap(base_census, path=['workclass', 'age'])
# grafico.show()

# grafico = px.treemap(base_census, path=['occupation', 'relationship', 'age'])
# grafico.show()

# grafico = px.parallel_categories(base_census, dimensions=['workclass','occupation', 'relationship', 'income'])
# grafico.show()

x_census = base_census.iloc[:, 0:14].values
y_census = base_census.iloc[:, 14].values

# label_encoder_test = LabelEncoder()
# teste = label_encoder_test.fit_transform(x_census[:,1])
# print(teste)

label_encoder_workclass = LabelEncoder()
label_encoder_education = LabelEncoder()
label_encoder_marital = LabelEncoder()
label_encoder_occupation = LabelEncoder()
label_encoder_relationship = LabelEncoder()
label_encoder_race = LabelEncoder()
label_encoder_sex = LabelEncoder()
label_encoder_country = LabelEncoder()

x_census[:,1] = label_encoder_workclass.fit_transform(x_census[:,1])
x_census[:,3] = label_encoder_education.fit_transform(x_census[:,3])
x_census[:,5] = label_encoder_marital.fit_transform(x_census[:,5])
x_census[:,6] = label_encoder_occupation.fit_transform(x_census[:,6])
x_census[:,7] = label_encoder_relationship.fit_transform(x_census[:,7])
x_census[:,8] = label_encoder_race.fit_transform(x_census[:,8])
x_census[:,9] = label_encoder_sex.fit_transform(x_census[:,9])
x_census[:,13] = label_encoder_country.fit_transform(x_census[:,13])

