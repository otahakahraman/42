import sys
from importlib import import_module
from importlib.metadata import PackageNotFoundError, version

packages: dict[str, str] = {
    "pandas": "Data manipulation",
    "numpy": "Numerical computation",
    "matplotlib": "Visualization",
}


def check_dependencies() -> bool:
    all_ok = True
    print("Checking dependencies:")
    for name, desc in packages.items():
        try:
            import_module(name)
            print(f"[OK] {name} ({version(name)}) - {desc} ready")
        except (ImportError, PackageNotFoundError):
            print(f"[MISSING] {name} - {desc} is not ready")
            all_ok = False
    return all_ok


def detect_manager() -> str:
    if "pypoetry" in sys.prefix.lower():
        return "Poetry"
    return "pip"


def compare_versions() -> None:
    print("\nInstalled package versions:")
    print(f"  {'Package':<12}{'Installed':<12}{'Declared (pip)':<16}"
          f"{'Declared (Poetry)'}")
    for name in packages:
        print(f"  {name:<12}{version(name):<12}{'any version':<16}{'*'}")
    print(f"Python: {sys.version.split()[0]}")
    print(f"Environment managed by: {detect_manager()}")


def show_differences() -> None:
    rows: list[tuple[str, str, str]] = [
        ("Dependency file", "requirements.txt", "pyproject.toml"),
        ("Install command", "pip install -r", "poetry install"),
        ("Exact versions", "not saved", "saved in poetry.lock"),
        ("Python version", "not enforced", "^3.10 enforced"),
        ("Virtual env", "you create it", "Poetry creates it"),
    ]
    print("\npip vs Poetry:")
    print(f"  {'':<17}{'pip':<18}{'Poetry'}")
    for label, pip_value, poetry_value in rows:
        print(f"  {label:<17}{pip_value:<18}{poetry_value}")


def analyze() -> None:
    import numpy as np
    import pandas as pd
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt

    print("\nAnalyzing Matrix data...")
    rng = np.random.default_rng()
    df = pd.DataFrame({"signal": rng.normal(0, 1, 1000)})
    print(f"Processing {len(df)} data points...")

    df["cumulative"] = df["signal"].cumsum()
    print("Generating visualization...")
    df["cumulative"].plot(title="Matrix Signal")
    plt.savefig("matrix_analysis.png")
    print("\nAnalysis complete!")
    print("Results saved to: matrix_analysis.png")


def main() -> None:
    print("LOADING STATUS: Loading programs...\n")
    if not check_dependencies():
        print("\nMissing dependencies! Install them with:")
        print("  pip:    pip install -r requirements.txt")
        print("  Poetry: poetry install")
        print("          poetry run python loading.py")
        sys.exit(1)
    analyze()
    compare_versions()
    show_differences()


if __name__ == "__main__":
    main()
