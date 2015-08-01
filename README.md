# millipede-efi-x64

Print a beautiful millipede

# How to run

The simplest way to run millipede.efi is to build the iso file (you will need mkisofs) by typing ```make all```

Then start a virtual machine with EFI enable and connect the CD.

At the UEFI shell prompt, type ```map``` to obtain a list of device.

You should have something like FS0. Type ```fs0:``` to go in the cd directory and simply run the millipede.efi application.

## Support

* [Stack Overflow](http://stackoverflow.com/questions/tagged/millipede)
* [Twitter](https://twitter.com/getmillipede)
* [#getmillipede](http://webchat.freenode.net?channels=%23getmillipede&uio=d4) on Freenode

## License

[MIT](https://github.com/getmillipede/millipede-efi-x64/blob/master/LICENSE)
