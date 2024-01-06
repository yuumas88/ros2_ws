from setuptools import find_packages
from setuptools import setup

setup(
    name='can_plugins2',
    version='0.0.1',
    packages=find_packages(
        include=('can_plugins2', 'can_plugins2.*')),
)
