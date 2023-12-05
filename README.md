[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/license-mit.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/not-a-bug-a-feature.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-reason.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/powered-by-coffee.svg)](https://forthebadge.com)

# gertrude-cli

**A CLI tool to make the creation of Makefiles easier!**

# Table of contents

- [Installation](#installation)
- [Prototype](#prototype)
    - [Flags](#flags)
    - [Examples](#examples)
- [Commit-norm](#commit-norm)
- [Updating](#updating)
- [Uninstallation](#uninstallation)

# Installation

All you have to do is to clone the repository and execute the installer.sh script inside it!
```bash
cd
git clone git@github.com:AshDev05/gertrude-cli.git
cd gertrude-cli
sudo sh installer.sh
```
Everything is done! 🌱

# Updating

To update gertrude you would simply need to execute :
```
gertrude update
```
Good plant 🌱

# Uninstallation

I am sorry that gertrude let you down. Here is how to get ride of her :
```
sudo rm -rf /opt/gertrude-cli
```
Bad plant.

# Prototype

gertrude [options](#flags)

## Flags

- -d *OPTIONAL* : Should specify a directory. [examples](#examples)
- \--var or -v *OPTIONAL* : Should specify a variable. [examples](#examples)
- \--rule or -r *OPTIONAL* : Should specify a rules with *deps* and *cmds*. [examples](#examples)
    - \--deps or -D : Should specify dependency for the given rule.
    - \--cmd or -c : Should specify a command for the given rule.
- \--epi or -e *OPTIONAL* : Creates a prefilled header for Makefiles. [examples](#examples)
- *config* : Configure gertrude **as you wish!** [examples](#examples)

### Examples
//

# Commit norm

Commits to this project should follow a commit norm.
When adding a major feature, the commit should be a sentence, starting with "Gertrude now...", followed by a sentence that makes sense (and a :seedling: if you want to use gitmoji).

When adding minor features, files, or others, it should start with [ADD], and then the files' names or a description.

Modifications should start with [MOD], except when they're made on the "base" of Gertrude, in which case it should be a comprehensible sentence describing what exactly was modified.

Removed files or folders should be commited as [REMOVE] or [REM] followed by a file name or folder path.

You should do your best to make logical and small commits, but you can stack commits by naming them "[ADD] file1, file2, minor-feature1 [MOD] feature1, file1". Gertrude's base's changes should be pushed using their own commit.

# License

The MIT License (MIT) 2023 - [AshDev05](https://github.com/AshDev05), [lg-epitech](https://github.com/lg-epitech). [LICENSE](LICENSE)