def light_spell_allowed_ingredients() -> list[str]:
    return (["earth", "air", "fire", "water"])


def light_spell_record(spell_name: str, ingredients: str) -> str:
    from .light_validator import validate_ingredients
    res = validate_ingredients(ingredients)
    if res.endswith("- VALID"):
        return f"Spell recorded: {spell_name} ({res})"
    return f"Spell rejected: {spell_name} ({res})"
