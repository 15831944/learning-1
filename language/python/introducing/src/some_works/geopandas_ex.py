'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install geopandas
# numpy pandas shapely fiona pyproj six cython
#sudo apt-get install proj-bin (on bionic is very old)
import geopandas
import matplotlib.pyplot as plt

world_file = geopandas.datasets.get_path('naturalearth_lowres')
world = geopandas.read_file(world_file)
cities_file = geopandas.datasets.get_path('naturalearth_cities')
cities = geopandas.read_file(cities_file)
base = world.plot(color='orchid')
cities.plot(ax=base, color='black', markersize=2)
plt.show()