
#cc = ${CXX}
cc = g++

OBJECT = opencv_gray.o
TARGET = opencv_gray

CCFLAGS = 

LDFLAGS = -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -lrt -lpthread -lm -ldl

$(TARGET): $(OBJECT)
	$(cc) $(LDFLAGS) -o $@ $(OBJECT)
%.o:%.c
	$(cc) $(CCFLAGS) -c -o $@ $<
clean:
	rm -f *.o result.jpg


