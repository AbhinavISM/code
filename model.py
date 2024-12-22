import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score, mean_squared_error
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D



# code for training the model :

# Step 1: Load the dataset
file_path = 'student_engagement_data.csv'  # Make sure this is the correct path
data = pd.read_csv(file_path)

# Step 2: Separate features and target variable
X = data[['Intrinsic_Motivation', 'Classroom_Environment']]
y = data['Engagement']

# Step 3: Train-Test Split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 4: Train a Linear Regression Model
model = LinearRegression()
model.fit(X_train, y_train)

# Step 5: Make predictions and evaluate
y_pred = model.predict(X_test)
mse = mean_squared_error(y_test, y_pred)

# Output the results
print("Mean Squared Error:", mse)
print("Model Coefficients:", model.coef_)
print("Model Intercept:", model.intercept_)










# code for Simulation of random data

# Define model coefficients obtained from training
a = model.coef_[0]  # replace with actual coefficient for Intrinsic Motivation
b = model.coef_[1]  # replace with actual coefficient for Classroom Environment
intercept = model.intercept_  # replace with actual intercept value

M_values = np.linspace(0, 10, 20)  # 20 evenly spaced values between 0 and 10
E_values = np.linspace(0, 10, 20)

# Step 1: Simulate Engagement over combinations of M and E
simulation_data = []
for M in M_values:
    for E in E_values:
        # Calculate Engagement based on the linear model
        Eng = a * M + b * E + intercept
        simulation_data.append({'Intrinsic_Motivation': M, 'Classroom_Environment': E, 'Engagement': Eng})

# Convert to DataFrame
simulation_df = pd.DataFrame(simulation_data)

# Step 2: Plotting 3D Line Graph
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Create a 3D line plot
ax.plot_trisurf(simulation_df['Intrinsic_Motivation'], simulation_df['Classroom_Environment'], simulation_df['Engagement'],
                cmap='viridis', linewidth=0.5, antialiased=True)

# Add labels and title
ax.set_xlabel('Intrinsic Motivation')
ax.set_ylabel('Classroom Environment')
ax.set_zlabel('Engagement')
ax.set_title('3D Line Graph: Student Engagement based on Intrinsic Motivation and Classroom Environment')

# Show the plot
plt.show()








# code for simulation of predicted and actual training data

fig = plt.figure(figsize=(12, 8))

# Subplot for the original data
ax1 = fig.add_subplot(121, projection='3d')
ax1.scatter(X_test['Intrinsic_Motivation'], X_test['Classroom_Environment'], y_test, c='r', marker='o', label='Original Data')
ax1.set_xlabel('Intrinsic Motivation')
ax1.set_ylabel('Classroom Environment')
ax1.set_zlabel('Engagement')
ax1.set_title('Original Data')

# Subplot for the predicted engagement values
ax2 = fig.add_subplot(122, projection='3d')
ax2.scatter(X_test['Intrinsic_Motivation'], X_test['Classroom_Environment'], y_pred, c='b', marker='^', label='Predicted Data')
ax2.set_xlabel('Intrinsic Motivation')
ax2.set_ylabel('Classroom Environment')
ax2.set_zlabel('Engagement')
ax2.set_title('Predicted Engagement by Model')

# Show the plots
plt.tight_layout()
plt.show()












# Calculate R-squared and Mean Squared Error
r2 = r2_score(y_test, y_pred)
mse = mean_squared_error(y_test, y_pred)

print(f"R-squared: {r2}")
print(f"Mean Squared Error: {mse}")
