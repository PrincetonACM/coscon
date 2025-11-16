import requests
import random

# Configuration
# Note: you can only submit up to 100 sequences per request
API_URL = "http://178.156.200.96/challenges/let-it-glow/scoring"
TEAM_ID = "team_id"
ACCESS_CODE = "access_code"


def generate_random_sequence():
    """Generate a random 135bp DNA sequence."""
    return "".join(random.choice("ACGT") for _ in range(135))


def submit_sequences(sequences):
    """Submit sequences to the scoring API."""
    payload = {"team_id": TEAM_ID, "access_code": ACCESS_CODE, "sequences": sequences}

    response = requests.post(API_URL, json=payload)

    if response.status_code == 200:
        data = response.json()
        print(f"Success! Attempts remaining: {data['attempts_remaining']}")
        print(f"Results: {data['results']}")
        return data
    else:
        print(f"Error: {response.json()}")
        return None


if __name__ == "__main__":
    # Example: submit 3 random sequences
    test_sequences = [generate_random_sequence() for _ in range(3)]

    print(f"Submitting {len(test_sequences)} sequences...")
    result = submit_sequences(test_sequences)
