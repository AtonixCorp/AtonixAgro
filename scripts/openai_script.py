import os
import requests
import yaml
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

# Load configuration from openai.yml
with open("openai.yml", "r") as file:
    config = yaml.safe_load(file)

api_key = os.getenv("OPENAI_API_KEY")
api_url = config["openai"]["api_url"]
model = config["openai"]["model"]
max_tokens = config["openai"]["max_tokens"]
temperature = config["openai"]["temperature"]
top_p = config["openai"]["top_p"]
n = config["openai"]["n"]
stop = config["openai"]["stop"]

headers = {
    "Content-Type": "application/json",
    "Authorization": f"Bearer {api_key}"
}

data = {
    "model": model,
    "prompt": "Translate the following English text to French: 'Hello, how are you?'",
    "max_tokens": max_tokens,
    "temperature": temperature,
    "top_p": top_p,
    "n": n,
    "stop": stop
}

response = requests.post(api_url, headers=headers, json=data)
if response.status_code == 200:
    result = response.json()
    print(result["choices"][0]["text"])
else:
    print(f"Error: {response.status_code}")