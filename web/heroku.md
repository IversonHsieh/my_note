#### Record heroku usage
- [Getting Started - nodejs](https://devcenter.heroku.com/articles/getting-started-with-nodejs#introduction)

##### Depoly the app

Get heroku URL  
```sh
$ heroku open
```

##### Scale the app

Check how many dynos are running using the `ps` command:  
```sh
$ heroku ps
=== web (Free): node index.js (1)
web.1: idle 2016/02/12 09:14:56 +0800 (~ 2h ago)
```

Scale the number of web dynos
```sh
$ heroku ps:scale web=0
```
```sh
$ heroku ps:scale web=1
```

##### Run the app locally
```sh
$ heroku local web
# However, in my ubuntu, I install nodejs-0.10.25 and no node command. I can use the command to test in local
$ nodejs index.js
```

##### Start a console

Launch a REPL process for experimenting in your app's environment:
```sh
$ heroku run node
```

For example, you will be able to run the following:
```javascript
> var cool = require('cool-ascii-faces')
> cool()
( ⚆ _ ⚆ )
```

run the `bash` command
```sh
$ heroku run bash
```

