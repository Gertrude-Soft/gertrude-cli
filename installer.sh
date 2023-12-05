#!/bin/bash

GREEN="\033[1;32m"

sudo rm -rf /tmp/gertrude_installer
git clone git@github.com:AshDev05/gertrude-cli.git /tmp/gertrude_installer
make -C /tmp/gertrude_installer/ re
sudo mkdir -p /opt/gertrude-cli
sudo cp -rf /tmp/gertrude_installer/* /opt/gertrude-cli
sudo cp /opt/gertrude-cli/gertrude /usr/bin
sudo rm -rf /opt/gertrude-cli/.git
sudo rm -rf /tmp/gertrude_installer

echo -e $GREEN"Good Plant\033[1;0m"
