#pragma once

class ViewingLoader {
public:
	ViewingLoader(const char *ViewingFile);

	void setViewing();
	int getWidth() const;
	int getHeight() const;

private:
	float eye_xyz[3];
	float vat_xyz[3];
	float vup_xyz[3];
	float fovy;
	float dnear;
	float dfar;
	float viewport_xywh[4];
};
