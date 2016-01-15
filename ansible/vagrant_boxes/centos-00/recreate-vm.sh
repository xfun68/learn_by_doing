#!/bin/sh

ip=$( cat Vagrantfile | egrep '^  config.vm.network' | cut -d'"' -f 4 )

vagrant destroy -f && \
  vagrant up && \
  cat $HOME/code/huawei/gocd/deploy/files/id_rsa_gocd.pub | ssh -i ./.vagrant/machines/default/virtualbox/private_key vagrant@${ip} "mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys"

