[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-reason.svg)](https://forthebadge.com)

[![forthebadge](https://forthebadge.com/images/badges/not-a-bug-a-feature.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/powered-by-coffee.svg)](https://forthebadge.com)

# gertrude-cli

**A CLI tool to make the creation of Makefiles easier!**

# Table of contents

- [Installation](#installation)
- [Updating](#updating)
- [Uninstallation](#uninstallation)
- [Prototype](#prototype)
    - [Flags](#flags)
    - [Examples](#examples)
- [Contribution](#contribution)
- [License](#license)

# Installation

All you have to do is to clone the repository and execute the installer.sh script inside it!
```bash
cd

git clone git@github.com:AshDev05/gertrude-cli.git

cd gertrude-cli

./installer.sh
```

We also advise everyone to check ```gertrude config``` before using to make gertrude behave as you wish! [Config](#config)

Everything is done! 🌱

# Updating

To update gertrude you would simply need to execute :
```
gertrude update
```
Good plant 🌱

# Uninstallation

We are sorry that gertrude let you down. Here is how to get rid of her :
```
sudo rm -rf /opt/gertrude-cli
```
Bad plant.

# Prototype

gertrude [options](#flags)

## Flags

- **-d** *OPTIONAL* : Should specify a directory. [See Example](#directory)
- **\--var** or **-v** *OPTIONAL* : Should specify a variable. [See Example](#variables)
- **\--rule** or **-r** *OPTIONAL* : Should specify a rules with *deps* and *cmds*. [See Example](#rules)
    - **\--deps** or **-D** : Should specify dependency for the given rule.
    - **\--cmd** or **-c** : Should specify a command for the given rule.
- **\--epi** or **-e** *OPTIONAL* : Creates a prefilled header for Makefiles. [See Example](#epiheader)
- **config** : Configure gertrude **as you wish!** [See Example](#config)

If Gertrude is called without options, it will generate a basic Makefile that you can modify in the directory where you executed her.

### Examples
- #### Directory
	- ```gertrude -d path/to/lib/ [...]``` ==> Gertrude will create a Makefile in the specified directory path/to/lib/

- #### Variables
	- ```gertrude -v SRC="$(wildcard *.c)"``` ==> Gertrude will create a Makefile containing the specified variable with name SRC and value $(wildcard *.c)

- #### Rules
	- ```gertrude -r lib -D $(OBJS_LIB) --cmd "echo Good Plant"``` ==> Gertrude will create a Makefile with the rule 'lib' which will depend on the object files for the lib, and will execute the command ```echo Good Plant```

- #### EpiHeader
	- ```gertrude [...] --epi``` ==> The Makefile will be started with the standard EPITECH school's header which is as follows:

```
##
## EPITECH PROJECT, 2023
## project_name
## File description:
## description
##
```

- #### Config
	- ```gertrude config``` ==> This will open the configuration file your set editor (defaults to nano). **Warning**, editing sections that are not meant to be edited will result in undefined behaviour. Such sections are marked with ```/* Do not edit above/below this line*/```. Editable values are clearly explained in a comment above the latter.



# Contribution

You are free to contribute to this project by forking your own copy and creating pull requests, which we will review. Commits to this project should follow a commit norm:

- "Gertrude now (...) 🌱" ==> Changes to the core functionalities of Gertrude, addition of a major feature.

- [ADD] (file name / description) ==> Addition of a minor feature, some files, or something else.

- [MOD] (changes) ==> Changes made to a minor feature, something that ***changes the behaviour***.

- [FIX] (changes) ==> Changes made to a minor feature to fix a bug, or to the coding style. These changes ***do not alter the behaviour***

- [REM] (file) ==> Removal of (a) specific file(s).

# License
[![forthebadge](https://forthebadge.com/images/badges/license-mit.svg)](https://forthebadge.com)

The MIT License (MIT) 2023 - [AshDev05](https://github.com/AshDev05), [lg-epitech](https://github.com/lg-epitech). [LICENSE](LICENSE)
