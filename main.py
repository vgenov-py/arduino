import requests as req
url = "https://datos.comunidad.madrid/catalogo/dataset/032474a0-bf11-4465-bb92-392052962866/resource/301aed82-339b-4005-ab20-06db41ee7017/download/municipio_comunidad_madrid.json"
res = req.get(url).json()["data"][0:75]
sups = str(list(map(lambda d:d["superficie_km2"], res)))
names = str(list(map(lambda d:d["municipio_nombre"], res)))
print(names.replace("[", "{").replace("]", "}").replace("'", '"'))
print(sups.replace("[", "{").replace("]", "}"))


