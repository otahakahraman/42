from .elements import create_air, create_earth
from elements import create_fire, create_water
air = create_air()
earth = create_earth()
fire = create_fire()
water = create_water()


def healing_potion() -> str:
    return (f"Healing potion brewed with '{earth}' and '{air}'")


def strength_potion() -> str:
    return (f"Strength potion brewed with '{fire}' and '{water}'")
