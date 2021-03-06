make:
	./scripts/build.sh

flash:
	./scripts/flash.sh

monitor:
	./scripts/monitor.sh

config:
	./scripts/menuconfig.sh

clean:
	rm -rf ./esp-idf/build/

erase:
	./scripts/erase_flash.sh

flashandtest:
	./scripts/flashandtest.sh
	
eraseandtest:
	make erase 
	make flashandtest
