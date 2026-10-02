from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    listed: list[str] = dark_spell_allowed_ingredients()
    allowed = ingredients.lower()
    for i in listed:
        if i in allowed:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
