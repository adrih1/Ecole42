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

# --- Configurer Nginx ---
COPY config/nginx.conf /etc/nginx/sites-available/default

# --- Configurer SSH ---
COPY config/sshd_config /etc/ssh/sshd_config

# Créer un utilisateur pour test connexion ssh
RUN useradd -m ahors \
    && mkdir -p /home/ahors/.ssh \
    && chmod 700 /home/ahors/.ssh \
    && echo "ahors:ftonion" | chpasswd \
    && usermod -aG sudo ahors

COPY config/ft_onion_ahors.pub /home/ahors/.ssh/authorized_keys
RUN chmod 600 /home/ahors/.ssh/authorized_keys \
    && chown -R ahors:ahors /home/ahors/.ssh

# --- Configurer torrc ---
RUN cp /etc/tor/torrc /etc/tor/torrc.default
COPY config/torrc /etc/tor/torrc

# --- Exposer le port web ---
EXPOSE 80 4242

# --- Lancer Tor puis Nginx ---
CMD service tor start && service ssh start && nginx -g "daemon off;"
