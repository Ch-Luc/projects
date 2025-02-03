import cv2
import numpy as np

# Charger l'image
image_path = 'C:/Users/produ/Documents/Apprentissage Cpp/projects/imageProcessing/template balatro full normal.jpg'
image = cv2.imread(image_path)

# Convertir en niveaux de gris
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Appliquer un flou pour réduire le bruit
blurred = cv2.GaussianBlur(gray, (5, 5), 0)

# Détecter les bords avec Canny
edges = cv2.Canny(blurred, 50, 150)

# Trouver les contours
contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Filtrer les contours basés sur la taille et la forme
card_contours = []
for contour in contours:
    approx = cv2.approxPolyDP(contour, 0.02 * cv2.arcLength(contour, True), True)
    if len(approx) == 4:  # Rechercher des quadrilatères
        x, y, w, h = cv2.boundingRect(approx)
        aspect_ratio = w / float(h)
        if 2.0 > aspect_ratio > 0.5 and w > 50 and h > 50:  # Ajuster selon les dimensions des cartes
            card_contours.append((x, y, w, h))

# Trier les cartes en bas et en haut
bottom_cards = []
top_cards = []
height, width, _ = image.shape
for x, y, w, h in card_contours:
    if y > height // 2:  # Partie inférieure de l'image
        bottom_cards.append((x, y, w, h))
    elif y < height // 3:  # Partie supérieure de l'image
        top_cards.append((x, y, w, h))

# Dessiner les cadres détectés
output_image = image.copy()
for x, y, w, h in bottom_cards:
    cv2.rectangle(output_image, (x, y), (x + w, y + h), (0, 255, 0), 2)
for x, y, w, h in top_cards:
    cv2.rectangle(output_image, (x, y), (x + w, y + h), (255, 0, 0), 2)

# Sauvegarder l'image avec les cadres détectés
cv2.imwrite('C:/Users/produ/Documents/Apprentissage Cpp/projects/imageProcessing/output_images.jpg', output_image)

# Afficher les résultats
print("Cartes en bas :", bottom_cards)
print("Cartes en haut :", top_cards)
