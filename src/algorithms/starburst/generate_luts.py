import math

image_width: int = 0
image_height: int = 0

# Como estratégia de compressão, vamos guardar as direções para onde o raio deve continuar.
# Sendo assim, também podemos pré-computar as direções (poderia ser memoização também, tanto faz)

cardinal_coordinates = f"""
const int CARDINAL_COORDINATES[9] = {{
         {-image_width - 1}, {-image_width}, {-image_width + 1},
         {-1}, {0}, {1},
         {image_width - 1}, {image_width}, {image_width + 1}
    }}
"""

# Uma colinha para eu não me perder:
# [ 0, 1, 2,
#   3, 4, 5,
#   6, 7, 8 ]
#
# [ (-1, +1), (0, +1), (+1, +1),
#   (-1,  0), (0,  0), (+1,  0),
#   (-1, -1), (0, -1), (+1, -1) ]

# Para gerar os raios, é um pouco mais complicado, mas dá pra entender

# Pense que temos 8 direções cardiais e o meio. E já que o raio avança, via de regra
# sempre um pixel apenas por vez, temos que calcular para onde ele vai.

# Tenha em mente que o contorno é baseado em 2 * PI * RAIO, e para não termos problemas
# com o preenchimento, precisamos de alguns raios a mais que isso

circle_radius: int = 0

ray_amount: int = 128

angle_lookup_table: str = f"""
const unsigned char LOOKUP_TABLE[{ray_amount}][{circle_radius}] = {{
"""

for ray in range(ray_amount):
    current_x: int = 0
    current_y: int = 0
    angle: float = ((2 * math.pi) / ray_amount) * ray
    for step in range(circle_radius):
        old_x: int = current_x
        old_y: int = current_y

        current_x = round(math.cos(angle) * step)
        current_y = round(math.sin(angle) * step)

        delta_x: int = current_x - old_x
        delta_y: int = current_y - old_y

        index: int = 0

        match delta_x:
            case 1:
                index += 2
            case 0:
                index += 1
            case _:
                index += 0

        match delta_y:
            case 1:
                index += 0
            case 0:
                index += 3
            case _:
                index += 6
        
        angle_lookup_table = angle_lookup_table + f"{{{index}}}, "

    angle_lookup_table = angle_lookup_table + "\n"
        
angle_lookup_table = angle_lookup_table + f"}}"
