import os
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

# Get client ID and secret from environment variables
ARDUINO_CLIENT_ID = os.getenv('ARDUINO_CLIENT_ID')
ARDUINO_CLIENT_SECRET = os.getenv('ARDUINO_CLIENT_SECRET')

# Ensure the environment variables are loaded
if not ARDUINO_CLIENT_ID or not ARDUINO_CLIENT_SECRET:
    raise ValueError("Client ID or Client Secret not found in environment variables")