Git config operation
-----------------------------
- [Caching your GitHub password in Git][git-config_passwd]
[git-config_passwd]: https://help.github.com/articles/caching-your-github-password-in-git/#platform-linux

        $ git config --global credential.helper cache
        # Set git to use the credential memory cache\

        $ git config --global credential.helper 'cache --timeout=3600'
        # Set the cache to timeout after 1 hour (setting is in seconds)

