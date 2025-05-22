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
    // Produits vectoriels pour chaque côté du triangle
    Fixed crossAB = crossProduct(a, b, point);  
    Fixed crossBC = crossProduct(b, c, point);
    Fixed crossCA = crossProduct(c, a, point);

    // Si tous les signes sont positifs ou tous négatifs, le point est à l'intérieur
    bool isInside = (crossAB > Fixed(0) && crossBC > Fixed(0) && crossCA > Fixed(0)) ||
                    (crossAB < Fixed(0) && crossBC < Fixed(0) && crossCA < Fixed(0));
    if (crossAB == Fixed(0) || crossBC == Fixed(0) || crossCA == Fixed(0)) {
        return false;
    }
    return isInside;
}