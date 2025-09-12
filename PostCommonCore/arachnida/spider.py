import sys
import os           # Handle files and directories
import requests     # Donwloading pages and images
import re           # Extract URL from images
from urllib.parse import urljoin, urlparse


DEFAULT_DEPTH = 5
DEFAULT_PATH = './data'
EXTENSIONS = ['.jpg', '.jpeg', '.gif', '.bmp']

def parse_args(args):
    # Valeurs par défaut
    options = {
        "recursive": False,
        "max_depth": DEFAULT_DEPTH,
        "path": DEFAULT_PATH,
        "url": None
    }

    i = 0
    while i < len(args):
        if args[i] == "-r":
            options["recursive"] = True
            i += 1
        elif args[i] == "-l":
            if i + 1 < len(args) and args[i+1].isdigit():
                options["max_depth"] = int(args[i+1])
                i += 2
            else:
                print("Erreur: -l doit être suivi d'un nombre")
                sys.exit(1)
        elif args[i] == "-p":
            if i + 1 < len(args):
                options["path"] = args[i+1]
                i += 2
            else:
                print("Erreur: -p doit être suivi d'un chemin")
                sys.exit(1)
        else:
            options["url"] = args[i]
            i += 1

    if options["url"] is None:
        print("Erreur: URL manquante")
        sys.exit(1)

    if not os.path.exists(options["path"]):
        os.makedirs(options["path"])

    return options

# Extract all images URL from the HTML text
def extract_images(html, base_url):
    # Find all <img> tags and gets the src
    img_urls = re.findall(r'<img [^>]*src="([^"]+)"', html, re.IGNORECASE)
    
    # Keep only images with our extensions | base_url is to transform a relative url into an absolute one
    img_urls = [urljoin(base_url, url) for url in img_urls if any(url.lower().endswith(ext) for ext in EXTENSIONS)]
    for url in img_urls:
        print({url})
    return img_urls



def fetch_page(url):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            extract_images(response.text, url)
            return response.text
        else:
            print(f"Error {response.status_code} while retrieving {url}")
            return None
    except Exception as e:
        print(f"Error while request {url} : {e}")    
        return None


def main():
    # Display Usage Methods
    if len(sys.argv) < 2:
        print("Usage: python spider.py [-r] [-l N] [-p PATH] URL")
        sys.exit(1)

    args = sys.argv[1:]
    # Parse Args
    options = parse_args(args)

    # Result of the parsing
    print("Options récupérées :")
    print(f" - Recursive : {options['recursive']}")
    print(f" - Max depth : {options['max_depth']}")
    print(f" - Path      : {options['path']}")
    print(f" - URL       : {options['url']}")

    fetch_page(options['url'])


if __name__ == "__main__":
    main()
