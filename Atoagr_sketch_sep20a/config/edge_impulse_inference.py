
import edgeimpulse as ei

# Change to an API key from your Edge Impulse project
ei.API_KEY = "your-api-key"

# Path to the trained model
model_path = "../script/model_training.ipynb"

# Print inference estimates
result = ei.model.profile(model=model_path)
print(result.summary())