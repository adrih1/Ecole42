FROM ubuntu:22.04

# --- Installer les dépendances de base + Nginx + torsocks + apt-transport-https ---
RUN apt-get update && apt-get install -y \
    curl \
    gpg \
    openssh-server \
    nginx \
    torsocks \
    apt-transport-https \
    wget \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# --- Créer le fichier tor.list et ajouter les entrées ---
RUN echo "deb [signed-by=/usr/share/keyrings/deb.torproject.org-keyring.gpg] https://deb.torproject.org/torproject.org jammy main" > /etc/apt/sources.list.d/tor.list
RUN echo "deb-src [signed-by=/usr/share/keyrings/deb.torproject.org-keyring.gpg] https://deb.torproject.org/torproject.org jammy main" >> /etc/apt/sources.list.d/tor.list

# --- Ajouter la clé GPG officielle de Tor ---
RUN wget -qO- https://deb.torproject.org/torproject.org/A3C4F0F979CAA22CDBA8F512EE8CBC9E886DDD89.asc \
    | gpg --dearmor \
    | tee /usr/share/keyrings/deb.torproject.org-keyring.gpg >/dev/null

# --- Installer Tor et le paquet de mise à jour des clés ---
RUN apt-get update && apt-get install -y \
    tor \
    deb.torproject.org-keyring \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# --- Informations sur l'origin des pages webs ---
RUN echo "Créaton d'un volume qui lie le dossier local .html à var/www/html"


# --- Configurer Nginx ---
RUN echo 'server { \
    listen 80 default_server; \
    listen [::]:80 default_server; \
    root /var/www/html; \
    index index.html; \
    server_name _; \
    charset utf-8; \
}' > /etc/nginx/sites-available/default

# --- Configurer SSH ---
RUN mkdir -p /var/run/sshd \
    # Configurer SSH pour écouter sur le port 4242
    && sed -i 's/#Port 22/Port 4242/' /etc/ssh/sshd_config \
    && sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config \
    && sed -i 's/#PasswordAuthentication yes/PasswordAuthentication yes/' /etc/ssh/sshd_config

# Créer un utilisateur pour test connexion ssh
RUN useradd -m ahors \
    && echo "ahors:ftonion" | chpasswd \
    && usermod -aG sudo ahors



# --- Ajouter la configuration du service caché dans torrc ---
RUN echo "HiddenServiceDir /var/lib/tor/hidden_service" >> /etc/tor/torrc \
    && echo "HiddenServicePort 4242 127.0.0.1:4242" >> /etc/tor/torrc \
    && echo "HiddenServicePort 80 127.0.0.1:80" >> /etc/tor/torrc

# --- Informer le correcteur où se trouve l'addresse du service caché ---
RUN echo "Le hostname du service caché sera généré dans /var/lib/tor/hidden_service/hostname après le premier run du container"

# --- Exposer le port web ---
EXPOSE 80 4242

# --- Lancer Tor puis Nginx ---
CMD service tor start && service ssh start && nginx -g "daemon off;"
