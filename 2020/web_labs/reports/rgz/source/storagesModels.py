from uuid import uuid4
from django.db import models
from taggit.managers import TaggableManager

class Storage(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    name = models.CharField(max_length=128)
    owner = models.ForeignKey('auth.User',related_name='storages',on_delete=models.CASCADE)
    tags = TaggableManager()
    def __str__(self):
        return str(id)

class Section(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    name = models.CharField(max_length=128)
    storage = models.ForeignKey(
        'Storage',
        related_name='sections',
        on_delete=models.CASCADE
    )

    def __str__(self):
        return str(id)