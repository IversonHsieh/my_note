## Python Django Note

*****
#### Install python django development environment in Linux server

```sh
$ sudo apt-get update
$ sudo apt-get -y upgrade
$ sudo apt-get -y install python-pip
$ sudo pip install virtualenv
```

*****
#### Create a virtual environment

```sh
$ virtualenv VENV
```

*****
#### Enter a virtual environment

```sh
$ source VENV/bin/activate
```

*****
#### Install Django in virtual environment

```sh
(VENV) $ pip install django
(VENV) $ django-admin startproject myweb
```

*****
#### Freeze installed pip package

```sh
(VENV) $ pip freeze > requirements.txt
```

*****
#### Setup environment from git to new PC

```sh
(VENV) $ git clone https://github.com/IversonHsieh/PythonWeb.git myweb
(VENV) $ cd myweb
(VENV) $ pip install -r 'requirements.txt'
```

*****
#### Run python web site

```sh
(VENV) $ python manage.py runserver 192.168.179.184:8000
```

*****
#### Run apache web site

```sh
(VENV) $ sudo service apache2 restart
```

*****
#### Google cloud console

- ip : 104.199.209.106












