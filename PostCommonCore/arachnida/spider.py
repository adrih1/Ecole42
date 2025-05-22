import sys

def parse_recursive_option(args, index):
    """Gère l'option -r."""
    return True, index

def parse_depth_option(args, index):
    """Gère l'option -l et retourne la profondeur."""
    if index + 1 < len(args):
        try:
            return int(args[index + 1]), index + 1
        except ValueError:
            raise ValueError("La profondeur (-l) doit être un entier.")
    else:
        raise ValueError("Aucun niveau de profondeur spécifié après -l.")

def parse_path_option(args, index):
    """Gère l'option -p et retourne le chemin."""
    if index + 1 < len(args):
        return args[index + 1], index + 1
    else:
        raise ValueError("Aucun chemin spécifié après -p.")

def parse_url(args, index, current_url):
    """Gère l'URL."""
    if current_url is not None:
        raise ValueError("Plusieurs URL spécifiées.")
    return args[index]

def parse_arguments(args):
    """
    Analyse les arguments et retourne les options configurées.
    """
    # Initialisation des paramètres par défaut
    recursive = False
    max_depth = 5
    path = "./data/"
    url = None

    i = 0
    while i < len(args):
        if args[i] == "-r":
            recursive, i = parse_recursive_option(args, i)
        elif args[i] == "-l":
            max_depth, i = parse_depth_option(args, i)
        elif args[i] == "-p":
            path, i = parse_path_option(args, i)
        else:
            url = parse_url(args, i, url)
        i += 1

    # Vérifier que l'URL est définie
    if url is None:
        raise ValueError("Aucune URL spécifiée.")

    return {
        "recursive": recursive,
        "max_depth": max_depth,
        "path": path,
        "url": url
    }

def main():
    if len(sys.argv) < 2:
        print("Usage : ./spider [-rlp] URL")
        return

    try:
        options = parse_arguments(sys.argv[1:])
        print(f"Options configurées :")
        print(f"  Recursive : {options['recursive']}")
        print(f"  Max Depth : {options['max_depth']}")
        print(f"  Save Path : {options['path']}")
        print(f"  URL       : {options['url']}")
    except ValueError as e:
        print(f"Erreur : {e}")

if __name__ == "__main__":
    main()
