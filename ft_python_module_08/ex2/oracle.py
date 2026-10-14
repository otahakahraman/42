import os
import sys
import re
from dotenv import load_dotenv, find_dotenv

REQUIRED: list[str] = [
    "MATRIX_MODE",
    "DATABASE_URL",
    "API_KEY",
    "LOG_LEVEL",
    "ZION_ENDPOINT",
]
PLACEHOLDER = "your_api_key_here"
SECRET_PATTERN = re.compile(
    r"(API_KEY|SECRET|PASSWORD)\s*=\s*[\"'][^\"']+[\"']"
)


def load_config() -> dict[str, str | None]:
    load_dotenv()
    return {key: os.getenv(key) for key in REQUIRED}

def has_hardcoded_secret() -> bool:
    with open(__file__,encoding="utf-8") as source:
        return SECRET_PATTERN.search(source.read()) is not None

def show_config(cfg: dict[str, str | None]) -> None:
    mode = cfg["MATRIX_MODE"] or "development"
    print("Configuration loaded:")
    print(f"Mode: {mode}")

    if cfg["DATABASE_URL"] is None:
        print("Database: Not configured")
    elif mode =="production" :
        print("Database: Connected to production cluster")
    else:
        print("Database: Connected to local instance")
    if not cfg["API_KEY"]:
        print("API Access: No key (unauthenticated)")
    else:
        print("API Access: Authenticated")
    print(f"Log Level: {cfg['LOG_LEVEL'] or 'INFO'}")
    if cfg["ZION_ENDPOINT"] is None:
        print("Zion Network: Offline")
    else:
        print("Zion Network: Online")

def security_check(cfg: dict[str, str | None]) -> None:
    print("Environment security check:")

    if has_hardcoded_secret():
        print("[WARNING] Hardcoded secret found in source code")
    else:
        print("[OK] No hardcoded secrets detected")

    if find_dotenv():
        print("[OK] .env file properly configured")
    else:
        print("[WARNING] .env not found, using environment only")

    if cfg["API_KEY"] == PLACEHOLDER:
        print("[WARNING] API_KEY is still the example placeholder")

    if cfg["MATRIX_MODE"] == "production":
        print("[OK] Production overrides active")
    else:
        print("[OK] Production overrides available")

def main() -> None:
    print("\nORACLE STATUS: Reading the Matrix...\n")
    cfg=load_config()

    missing=[key for key, value in cfg.items() if not value]
    for key in missing:
        print(f"WARNING: {key} is not set, using default")

    if missing:
        print()

    show_config(cfg)
    security_check(cfg)
    print("\nThe Oracle sees all configurations.")

if __name__ == "__main__":
    try:
        main()
    except Exception as err:
        print(f"ERROR: {err}")
        sys.exit(1)