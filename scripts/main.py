from config.arduino_oauthlib_config import ARDUINO_CLIENT_ID, ARDUINO_CLIENT_SECRET
from oauthlib.oauth2 import BackendApplicationClient
from requests_oauthlib import OAuth2Session
import iot_api_client as iot
from iot_api_client.rest import ApiException
from iot_api_client.configuration import Configuration

# Fetch the OAuth2 token
def fetch_token():
    oauth_client = BackendApplicationClient(client_id=ARDUINO_CLIENT_ID)
    token_url = "https://api2.arduino.cc/iot/v1/clients/token"

    oauth = OAuth2Session(client=oauth_client)
    token = oauth.fetch_token(
        token_url=token_url,
        client_id=ARDUINO_CLIENT_ID,
        client_secret=ARDUINO_CLIENT_SECRET,
        include_client_id=True,
        audience="https://api2.arduino.cc/iot",
    )

    return token.get("access_token")

# Main function to interact with the Arduino IoT Cloud API
def main():
    access_token = fetch_token()

    # Configure and instance the API client
    client_config = Configuration(host="https://api2.arduino.cc/iot")
    client_config.access_token = access_token
    client = iot.ApiClient(client_config)

    # Interact with the devices API
    devices_api = iot.DevicesV2Api(client)

    try:
        resp = devices_api.devices_v2_list()
        print(resp)
    except ApiException as e:
        print("Got an exception: {}".format(e))

if __name__ == "__main__":
    main()