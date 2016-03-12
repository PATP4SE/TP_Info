#include "Utilities.h"

Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

void Utilities::ExportImage(ofImage *_image)
{
	ofFileDialogResult dialog;
	dialog = ofSystemSaveDialog("image.png", "Message Name");

	if (dialog.bSuccess)
	{
		string extension = dialog.fileName.substr(dialog.fileName.find_last_of(".") + 1);
		if (extension == "png" || extension == "jpg" || extension == "bmp" || extension == "gif")
		{
			_image->save(dialog.filePath);
		}
		else
		{
			wstring s(L"Le nom du fichier doit contenir le format(png, jpg, bmp, gif)");
			wstring s2(L"Erreur");
			MessageBox(NULL, (LPCWSTR)s.c_str(), (LPCWSTR)s2.c_str(), MB_OK | MB_ICONERROR);
		}
	}
}

ofImage* Utilities::ImportImage()
{
	ofImage *image = new ofImage();

	image = new ofImage();
	ofSetColor(255);
	ofFileDialogResult dialog;
	dialog = ofSystemLoadDialog("Importer une image");
	if (dialog.bSuccess)
	{
		string extension = dialog.fileName.substr(dialog.fileName.find_last_of(".") + 1);
		transform(extension.begin(), extension.end(), extension.begin(), (int(*)(int))tolower);
		if (extension == "png" || extension == "jpg" || extension == "bmp" || extension == "gif")
		{
			image->load(dialog.filePath);
		}
		else
		{
			wstring s(L"Le fichier doit avoir un format d'image(png, jpg, bmp, gif)");
			wstring s2(L"Erreur");
			MessageBox(NULL, (LPCWSTR)s.c_str(), (LPCWSTR)s2.c_str(), MB_OK | MB_ICONERROR);
		}
	}

	return image;
}