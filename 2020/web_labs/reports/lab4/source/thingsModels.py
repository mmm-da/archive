from uuid import uuid4
from django.db import models
from taggit.managers import TaggableManager

class Thing(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    name = models.CharField(max_length=100)
    description = models.TextField()
    category = models.ForeignKey(
        'ThingCategory',
        related_name='things',
        blank=True,
        null=True,
        on_delete=models.CASCADE
    )

    tags = TaggableManager()
    def __str__(self):
        return str(id)

class ThingInstance(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    section = models.ForeignKey(
        'storages.Section',
        related_name='things_in_sections',
        on_delete=models.CASCADE
    )
    type = models.ForeignKey(
        'Thing',
        related_name='things_instances',
        on_delete=models.CASCADE
    )
    count = models.PositiveIntegerField()

    def __str__(self):
        return str(id)

class ThingCategory(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    name = models.CharField(max_length=100)
    icon_label = models.IntegerField()

    def __str__(self):
        return str(id)