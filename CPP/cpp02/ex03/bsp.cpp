#include "bsp.hpp"

// Fonction pour calculer le produit vectoriel entre deux vecteurs (AB) et (AP)
static Fixed crossProduct(Point const a, Point const b, Point const p) 
{
    // Vecteurs AB = (b.x - a.x, b.y - a.y), AP = (p.x - a.x, p.y - a.y)
    Fixed abx = b.getX() - a.getX(); // x de AB
    Fixed aby = b.getY() - a.getY(); // y de AB
    Fixed apx = p.getX() - a.getX(); // x de AP
    Fixed apy = p.getY() - a.getY(); // y de AP

    // Calcul du produit vectoriel (AB x AP)
    return abx * apy - aby * apx;
}


bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // On calcule les produits vectoriels pour chaque côté du triangle
    Fixed crossAB = crossProduct(a, b, point);  // Produit vectoriel de (AB) et (AP)
    Fixed crossBC = crossProduct(b, c, point);  // Produit vectoriel de (BC) et (BP)
    Fixed crossCA = crossProduct(c, a, point);  // Produit vectoriel de (CA) et (CP)

    // Vérification que les produits vectoriels ont tous le même signe
    // Si tous les signes sont positifs ou tous négatifs, le point est à l'intérieur
    bool isInside = (crossAB > Fixed(0) && crossBC > Fixed(0) && crossCA > Fixed(0)) ||
                    (crossAB < Fixed(0) && crossBC < Fixed(0) && crossCA < Fixed(0));

    // Si le point est sur un bord, il retourne false
    if (crossAB == Fixed(0) || crossBC == Fixed(0) || crossCA == Fixed(0)) {
        return false;
    }

    return isInside;
}