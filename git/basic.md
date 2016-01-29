Git basic operation
------------------------------------
#### [To grab a complete copy of another user's repository][git-clone]
[git-clone]: https://help.github.com/articles/fetching-a-remote/

	$ git clone [github url]
	ex: git clone https://github.com/IversonHsieh/my_note.git

#### [Grabs all the new remote-tracking branches and tags without merging those changes into your own branches][git-clone]

	$ git fetch [remotename]
	ex: git fetch

#### [Merging combines your local changes with changes made by others][git-clone]

	$ git merge [remotename/branchname]
	ex: git merge

#### [git pull is a convenient shortcut for completing both `git fetch` and `git merge`][git-clone]

	$ git pull [remotename branchname]
	ex: git pull

#### [push to a remote][git-push]
[git-push]: https://help.github.com/articles/pushing-to-a-remote/

	$ git push <REMOTENAME> <BRANCHNAME> 
	ex: git push
	ex: git push origin master

#### [git ignore files][git-ignore]
[git-ignore]: http://huan-lin.blogspot.com/2012/04/git-ignore-file.html

	$ vim <work repo>/.gitignore

        
