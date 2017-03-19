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
(VENV) $ git clone https://github.com/IversonHsieh/PythonWeb.git
(VENV) $ cd myweb
(VENV) $ pip install -r 'requirements.txt'
```




















