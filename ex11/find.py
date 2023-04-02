import requests

user_pokemon = input ("Enter the name of a Pokemon: ")

if (user_pokemon.strip() == ""):
    print("You did not enter a pokemon")
    quit()
user_pokemon = user_pokemon.lower()
r = requests.get("https://pokeapi.co/api/v2/pokemon/" + user_pokemon) # API pokemon must be called in lowercase

# Means pokemon exists
if (r.status_code == 200):
    print("Name: " + user_pokemon.capitalize())
else:
    print("Pokemon doesn't exist")
    quit()

print("Abilities:")
for i in r.json()["abilities"]:
    print("- " + i["ability"]["name"])