git reset operation
-------------------------
#### git reset [<tree-ish>] <paths>...

This means that git reset <paths> is the opposite of git add <path>.

    # Add git-reset.md to staging area
    $ git add git-reset.md
    # Undo git-reset.md to untracking area
    $ git reset HEAD git-reset.md

#### git reset [<mode>] [<commit>]

Does not touch the index file or the working tree at all (but resets the head to <commit>)

    # Move HEAD to last 1 HEAD but no change in working area.
    # We can see some files are put in staging area.
    $ git reset --soft HEAD~1
    # Undo the operation
    # Use `git reflog` to get which HEAD you want to undo
    $ git reset HEAD@{1}
    $ git reset [your hash number]


