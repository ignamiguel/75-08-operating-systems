# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  config.vm.box = 'ubuntu/xenial64'

  config.vm.network 'forwarded_port', guest: 9393, host: 9393
  config.vm.hostname = '75-08-operating-systems'
  config.vm.provider 'virtualbox' do |vb|
    vb.memory = '1024'
    vb.name = '75-08-operating-systems'
  end

  config.vm.provision 'shell', privileged: false, inline: <<-SHELL
    sudo apt-get update
    sudo apt-get install -y build-essential git

  SHELL
end
